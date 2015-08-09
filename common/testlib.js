var util = require("util")
var path = require("path")

Object.defineProperty(global, '__stack', {
    get: function() {
        var orig = Error.prepareStackTrace;
        Error.prepareStackTrace = function(_, stack) {
	    return stack;
	};
        var err = new Error;
        Error.captureStackTrace(err, arguments.callee);
        var stack = err.stack;
        Error.prepareStackTrace = orig;
        return stack;
    }
});

Object.defineProperty(global, '__file', {
    get: function() {
        return __stack[2].getFileName();
    }
});

Object.defineProperty(global, '__line', {
    get: function() {
        return __stack[2].getLineNumber();
    }
});

Object.defineProperty(global, '__function', {
    get: function() {
        return __stack[2].getFunctionName();
    }
});


var TESTLIB = {
    SET_FILE: function(filename) {
	this.filename = filename;
    },
    
    ASSERT_TRUE: function(expr) {
	if (expr)
	{
	    console.log("ASSERT_TRUE:\t[PASS]")
	}
	else
	{
	    console.log("ASSERT_TRUE:\t[FAIL]")
	    console.log(util.format("%s:%d: error: ASSERT_TRUE failed.", path.basename(__file), __line))
	}
    },

    ASSERT_FALSE: function(expr) {
	if (!expr)
	{
	    console.log("ASSERT_FALSE:\t[PASS]")
	}
	else
	{
	    console.log("ASSERT_FALSE:\t[FAIL]")
	    console.log(util.format("%s:%d: error: ASSERT_FALSE failed.", path.basename(__file), __line))
	}
    },
    
};

module.exports = TESTLIB;
