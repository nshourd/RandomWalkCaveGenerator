#ifndef MAP_H
#define MAP_H


class map
{
private:
    int rows;
    int cols;
public:
    map(int r, int c);
    void generate(char cave[30][50]);
    void display(char cave[30][50]);
    void save(char cave[30][50]);
    void read(char cave[30][50]);
};

#endif // MAP_H
