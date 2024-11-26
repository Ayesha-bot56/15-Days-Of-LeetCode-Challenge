var reverseStr = function(s, k) {
    let result = '';
    for (let i = 0; i < s.length; i += 2 * k) {
        let chunk = s.slice(i, i + k);
        result += chunk.split('').reverse().join('') + s.slice(i + k, i + 2 * k);
    }
    return result;
};
