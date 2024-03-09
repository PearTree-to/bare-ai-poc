#include <assert.h>
#include <bare.h>
#include <js.h>
#include <stdlib.h>

// Function to perform addition
static double add(double left, double right) {
  return left + right;
}

static js_value_t *
bare_sum(js_env_t *env, js_callback_info_t *info) {
  int err;
  
  size_t argc = 2;
  js_value_t *argv[2];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 2);
  
  double left;
  err = js_get_value_double(env, argv[0], &left);
  assert(err == 0);
  
  double right;
  err = js_get_value_double(env, argv[1], &right);
  assert(err == 0);
  
  // Use the standalone add function
  double resultValue = add(left, right);

  js_value_t *result;
  err = js_create_double(env, resultValue, &result);
  assert(err == 0);

  return result;
}

static js_value_t *
init(js_env_t *env, js_value_t *exports) {
  {
    js_value_t *fn;
    js_create_function(env, "sum", -1, bare_sum, NULL, &fn);
    js_set_named_property(env, exports, "sum", fn);
  }
  
  return exports;
}

BARE_MODULE(first, init)
