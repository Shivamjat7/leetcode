class Solution {
public:
    unordered_map<int ,string>hash;
    int id=0;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        hash[id]=longUrl;
        id++;
        return to_string(id-1);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return hash[stoi(shortUrl)];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));