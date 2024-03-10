// 1713번 = 후보 추천하기

#include <iostream>
#include <vector>

using namespace std;

class Candidate {   
    private:
        bool isUploaded; 
        int vote;
        int created_at;
    
    public:
        Candidate() {
            this->isUploaded = false;
            this->vote = 0;
            this->created_at = 10000;
        }
        void updateVote() {
            this->vote++;
        }
        void uploadCandidate(int t) {
            this->isUploaded = true;
            this->created_at = t;
        }
        void deleteCandidate() {
            this->isUploaded = false;
            this->vote = 0;
            this->created_at = 10000;
        }
        bool getIsUploaded() {
            return this->isUploaded;
        }
        int getVote() {
            return this->vote;
        }
        int getCreatedAt() {
            return this->created_at;
        }
};

int N, T, vote;
int cnt;
vector<Candidate> vec;

int findVictim() {
    int minVote = 10000, oldestTime = 10000, victim;
    for(int i = 1; i <= 100; ++i) {
        if(vec[i].getIsUploaded()) { // 해당 후보자가 이미 걸려있는 경우
            if(minVote > vec[i].getVote() || (minVote == vec[i].getVote() && oldestTime > vec[i].getCreatedAt())) {
                victim = i;
                minVote = vec[i].getVote(); 
                oldestTime = vec[i].getCreatedAt();
            }
        }
    }
    return victim;
}

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> N >> T;

    vec.assign(101, Candidate());

    for(int t = 1; t <= T; ++t) {
        cin >> vote;
        if(vec[vote].getIsUploaded()) {
            vec[vote].updateVote(); 
        } else {
            if(cnt >= N) { // 초기화 필요
                vec[findVictim()].deleteCandidate();
                vec[vote].uploadCandidate(t);
                vec[vote].updateVote();
            } else {
                vec[vote].uploadCandidate(t);
                vec[vote].updateVote();
                cnt++;
            }
        }
    }

    for(int i = 1; i <= 100; ++i) {
        if(vec[i].getIsUploaded()) {
            cout << i << ' ';
        }
    }

    return 0;

}