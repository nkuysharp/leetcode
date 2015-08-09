/**
* @param {string} s
* @param {string} t
* @return {boolean}
*/

var isAnagram = function(s, t) {

    if(s.length !== t.length)
	return false;
    
    var cnt = [];
    for (var i = 0; i<26; i++)
    {
	cnt.push(0);
    }
    
    for (i = 0; i < s.length; i++)
    {
	cnt[s.charCodeAt(i) - 'a'.charCodeAt()] += 1;
	cnt[t.charCodeAt(i) - 'a'.charCodeAt()] -= 1;
    }

    for (i = 0; i < 26; i++)
    {
	if (cnt[i] !== 0)
	    return false;
    }
    return true;
};


module.exports = isAnagram;


