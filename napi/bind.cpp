#include <node_api.h>
#include <assert.h>
#include <iostream>
#include <string>

class Test {
    std::string m_name;

public:
    Test(const std::string& name): m_name(name) {}

    const char* getName() const { return m_name.c_str(); }

    void accessName() {
        std::cout << "Inside: " << __func__ << "!\n";
        std::cout << "Name is: " << m_name << "\n\n";
    }
};

napi_value CreateTestObject(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);

    size_t str_len;
    size_t str_len_read;
    napi_get_value_string_utf8(env, args[0], nullptr, 0, &str_len);
    char* str = new char[str_len + 1];
    napi_get_value_string_utf8(env, args[0], str, str_len + 1, &str_len_read);

    Test* test = new Test(str);
    delete[] str; // Free the string after use

    test->accessName();

    napi_value jsObject;
    napi_create_external(env, test, [](napi_env env, void* finalize_data, void* finalize_hint) {
        delete static_cast<Test*>(finalize_data);
    }, nullptr, &jsObject);

    return jsObject;
}

napi_value AccessNameOfObject(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);

    Test* test;
    napi_get_value_external(env, args[0], reinterpret_cast<void**>(&test));

    test->accessName();

    napi_value result;
    napi_get_undefined(env, &result);
    return result;
}

napi_value Init(napi_env env, napi_value exports) {
    napi_value createTestObjectFunc;
    napi_create_function(env, "createTestObject", NAPI_AUTO_LENGTH, CreateTestObject, nullptr, &createTestObjectFunc);
    napi_set_named_property(env, exports, "createTestObject", createTestObjectFunc);

    napi_value accessNameOfObjectFunc;
    napi_create_function(env, "accessNameOfObject", NAPI_AUTO_LENGTH, AccessNameOfObject, nullptr, &accessNameOfObjectFunc);
    napi_set_named_property(env, exports, "accessNameOfObject", accessNameOfObjectFunc);

    return exports;
}

NAPI_MODULE(NODE_GYP_MODULE_NAME, Init)
