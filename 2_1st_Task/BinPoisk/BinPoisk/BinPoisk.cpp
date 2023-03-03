#include <iostream>
#include <vector>
#include <chrono>
#include <cmath>
#include <iterator>
#include <list>
#include <forward_list>



using namespace std;

class LogDuration {
public:
    LogDuration(string id)
        : id_(move(id)) {
    }

    ~LogDuration() {
        const auto end_time = chrono::steady_clock::now();
        const auto dur = end_time - start_time_;
        cout << id_ << ": ";
        cout << "operation time"
            << ": " << std::chrono::duration_cast<std::chrono::milliseconds>(dur).count()
            << " ms" << std::endl;
    }

private:
    const std::string id_;
    const std::chrono::steady_clock::time_point start_time_ = std::chrono::steady_clock::now();
};


template <class Iterator, typename T>
int BinSearch(Iterator iter1, Iterator iter2, int a, T Cont) {
    if constexpr (is_same_v<typename iterator_traits<Iterator>::iterator_category, random_access_iterator_tag>) {
        auto iter1 = Cont.begin();
        auto iter2 = Cont.end();
        auto mid = (iter1 + (iter2 - iter1) / 2);
        while (1 < iter2 - iter1) {
            mid = (iter1 + (iter2 - iter1) / 2);
            if (*mid >= a) {
                iter2 = mid;
            }
            else {
                iter1 = mid;
            }


            if (*mid == a)
                return mid - Cont.begin();

            //cout << *iter1 << " " << *iter2 << " " << *mid << endl;
        };
        if (*iter1 == a)
            return 0;
        return -1;
    }
    else if constexpr (is_same_v<typename iterator_traits<Iterator>::iterator_category, bidirectional_iterator_tag>) {
        auto iter1 = Cont.begin();
        auto iter2 = Cont.end();
        auto mid = Cont.begin();
        int l = Cont.size();
        while (l > 0) {
            int i = 0;
            auto mid = iter1;
            for (i = 0; i < l / 2; ++i, ++mid);
            if (*mid < a) {
                for (i = 0; i < l / 2; ++i, ++iter1);
                l = l - i;
            }
            else {
                for (i = 0; i < l / 2; ++i, iter2--);
                l = l - i;
            };
            //cout <<*iter1<<" "<< *mid<< " " << *iter2 << endl;

            if (*mid == a) {

                auto fin = Cont.begin();
                int i = 0;
                while (*fin != a) {
                    ++fin;
                    i++;
                }
                return i;
            }
            if (l == 1 and *iter1 != a and *iter2 != a)
                return -1;
        }
        if (*Cont.begin() == a)
            return 0;
    }
    else {
        auto iter1 = Cont.begin();
        auto iter2 = Cont.end();
        auto mid = Cont.begin();
        int l = 1;
        while (iter1 != iter2) {
            iter1++;
            l++;
        }
        iter1 = Cont.begin();
        int rPos = l - 1;
        while (l > 0) {
            int i = 0;
           
            auto mid = iter1;

            for (i = 0; i < l / 2; ++i, ++mid);
            if (*mid < a) {
                for (i = 0; i < l / 2; ++i, ++iter1);
                l = l - i;
            }
            else {
                for (i = 0; i < l / 2; ++i, rPos--);
                iter2 = Cont.begin();
                for (int j = 0; j < rPos; ++j, ++iter2)
                l = l - i;
            };
            //cout <<*iter1<<" "<< *mid<< " " << *iter2 << endl;

            if (*mid == a) {

                auto fin = Cont.begin();
                int i = 0;
                while (*fin != a) {
                    ++fin;
                    i++;
                }
                return i;
            }
            if (l == 1 and *iter1 != a and *iter2 != a)
                return -1;
        }
        if (*Cont.begin() == a)
            return 0;
    }
};

int main() {
    vector<int> v = { 1,2,4,5,6,7 };
    auto ItV1 = v.begin();
    auto ItV2 = v.end();
    cout << "RA iterators: "<<BinSearch(ItV1, ItV2, 3, v) << endl;


    list<int> a = { 1,2,4,5,6,7 };
    auto It1 = a.begin();
    auto It2 = a.end();
    cout << "Bidirectional iterators: " << BinSearch(It1, It2, 3, a)<<endl;

    forward_list<int> Fl = { 1,2,4,5,6,7 };
    auto ItFl1 = Fl.begin();
    auto ItFl2 = Fl.end();
    cout << "Forward iterators: " << BinSearch(ItFl1, ItFl2, 7, Fl) << endl;

}