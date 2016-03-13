#ifndef INCLUDED_PAIR
#define INCLUDED_PAIR

#define Regular typename
#define Semiregular typename

template<Semiregular T1, Semiregular T2>
struct pair {
    T1 first;
    T2 second;

    pair()
    {
    }

    pair(const T1& f, const T2& s)
      : first(f)
      , second(s)
    {
    }

};

template<Regular T1, Regular T2>
bool operator==(const pair<T1, T2>& p1, const pair<T1, T2>& p2)
{
    return p1.first == p2.first && p1.second == p2.second;
}

template<Regular T1, Regular T2>
bool operator!=(const pair<T1, T2>& p1, const pair<T1, T2>& p2)
{
    return !(p1 == p2);
}

#endif
