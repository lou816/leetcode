// Note: This is a companion problem to the System Design problem: Design TinyURL.
// TinyURL is a URL shortening service where you enter a URL such as https://leetcode.com/problems/design-tinyurl and it returns a short URL such as http://tinyurl.com/4e9iAk. Design a class to encode a URL and decode a tiny URL.

// There is no restriction on how your encode/decode algorithm should work. You just need to ensure that a URL can be encoded to a tiny URL and the tiny URL can be decoded to the original URL.

// Implement the Solution class:

// Solution() Initializes the object of the system.
// String encode(String longUrl) Returns a tiny URL for the given longUrl.
// String decode(String shortUrl) Returns the original long URL for the given shortUrl. It is guaranteed that the given shortUrl was encoded by the same object.
 

// Example 1:

// Input: url = "https://leetcode.com/problems/design-tinyurl"
// Output: "https://leetcode.com/problems/design-tinyurl"

// Explanation:
// Solution obj = new Solution();
// string tiny = obj.encode(url); // returns the encoded tiny url.
// string ans = obj.decode(tiny); // returns the original url after deconding it.
 

// Constraints:

// 1 <= url.length <= 104
// url is guranteed to be a valid URL.

//My way

typedef struct 
{
    char key[10];
    char val[10000];
    UT_hash_handle hh;
    /* data */
}HashTable;

HashTable *table = NULL;
char map[62] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";


/** Encodes a URL to a shortened URL. */
char* encode(char* longUrl) {
    HashTable *node = (HashTable*)malloc(sizeof(HashTable) * 1);
    char *newUrl = (char*)malloc(sizeof(char) * 19);
    srand(time(NULL));
    longUrl[strlen(longUrl)] = '\0';
    char *key = (char*)malloc(sizeof(char) * 10);
    for(int i = 0; i < 9; i++)
        key[i]= map[rand() % 62];
    key[9] = '\0';
    HashTable *tmp;
    HASH_FIND_STR(table, key, tmp);
    while(tmp)
    {
        for(int i = 0; i < 9; i++)
            key[i]= map[rand() % 62];
        key[9] = '\0';
        HASH_FIND_STR(table, key, tmp);
    }
    memcpy(node->key, key, 10);
    memcpy(node->val, longUrl, strlen(longUrl));
    node->val[strlen(longUrl)] = '\0';
    HASH_ADD_STR(table, key, node);
    sprintf(newUrl, "https://%s", key);
    return newUrl;
}

/** Decodes a shortened URL to its original URL. */
char* decode(char* shortUrl) {
    char *key = (char*)malloc(sizeof(char) * 10);
    memcpy(key, &shortUrl[8], 10);
    HashTable *tmp;
    HASH_FIND_STR(table, key, tmp);
    return tmp->val;
}

// Your functions will be called as such:
// char* s = encode(s);
// decode(s);