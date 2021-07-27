#include "Problems1.h"

#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

static string popularGenre(const map < string, vector<pair<int, size_t>>> &songs) {
    int maxSum = 0;
    string genre = "";
    
    for (auto const& iter : songs) {
        int sum = 0;
        for (size_t i = 0; i < iter.second.size(); i++) {
            sum += iter.second[i].first;
        }

        if (maxSum < sum) {
            maxSum = sum;
            genre = iter.first;
        }
    }

    return genre;
}


static vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;

    map < string, vector<pair<int, size_t>>> songs;
    
    for (size_t i = 0; i < genres.size(); i++) {
        if (songs.find(genres[i]) == songs.end())
            songs.insert({ genres[i], { {plays[i], i } } });
        else {
            songs[genres[i]].push_back({plays[i], i});
        }
    }   // O(n)


    
    for (auto &iter : songs) {
        sort(iter.second.begin(), iter.second.end(),
             [](pair<int, size_t> a, pair<int, size_t> b) { return a.first > b.first; });
    } // O(lgn?)

    string maxGenre;
    while ((maxGenre = popularGenre(songs)) != "") {
        if (songs[maxGenre].size() == 1) {
            answer.push_back(songs[maxGenre][0].second);
        } else {
            answer.push_back(songs[maxGenre][0].second);
            answer.push_back(songs[maxGenre][1].second);
        }

        songs.erase(maxGenre);
    }

    return answer;
}

void solution_1_4() {
    AutomatedInput Input;
    Input.set(
        "1 "

        "5 "
        "classic pop classic classic pop "
        "500 600 150 800 2500 "
    );

    int T;
    Input >> T;

    for (int trial = 0; trial < T; trial++) {
        vector<string> genres;
        vector<int> plays;
        int n;
        string g; int p;

        Input >> n;
        for (int i = 0; i < n; i++) {
            Input >> g;
            genres.push_back(g);
        }
        
        for (int i = 0; i < n; i++) {
            Input >> p;
            plays.push_back(p);
        }

        vector<int> res = solution(genres, plays);
        for (size_t i = 0; i < res.size(); i++)
            cout << res[i];
        cout << endl;
    }
}