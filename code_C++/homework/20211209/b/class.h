#ifndef CLASS_H
#define CLASS_H

class Clock {
private:
public:
	int hh, mm, ss;
    void input();
    void output();
};

bool operator < (Clock a, Clock b);
Clock operator - (Clock a, Clock b);

#endif /* CLASS_H */
