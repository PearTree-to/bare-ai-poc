const addon = require('./build/Release/addon');

// Assuming you have a method called createTestObject exposed from your addon
const testObj = addon.createTestObject('TestName');

// Assuming you have a method called accessNameOfObject exposed from your addon
addon.accessNameOfObject(testObj);
