#include<iostream>
#include <stdio.h>
#include <fstream>
using namespace std;

class Point
{
public:
    int x, y;
    Point() {}
    Point(int val1, int val2) {
        x = val1;
        y = val2;
    }
};

template <typename T>
class ListNode
{
    template <typename Q>
    friend class Queue;
    public:
        ListNode( const T &info )
        : coor( info ), nextPtr( NULL ), prevPtr( NULL )
        {
        }

        ListNode operator =(const ListNode &rhs) const {
            return 0;
        }
        T getCoor() {
            return coor;
        }

    private:
        T coor;
        ListNode *nextPtr;
        ListNode *prevPtr;
};

template <typename T>
class Queue {
    public:
        Queue() {
            head = tail = NULL;
        }
        ~Queue() {
            delete head;
        }
        void push(const T &number) {
            if(head) {
                tail->nextPtr = new ListNode<T>(number);
                tail->nextPtr->prevPtr = tail;
                tail = tail->nextPtr;
            } else {
                head = new ListNode<T>(number);
                tail = head;
            }
        }

        void push_back(const T &number) {
            if(tail) {
                head->prevPtr = new ListNode<T>(number);
                head->prevPtr->nextPtr = head;
                head = head->prevPtr;
            } else {
                tail = new ListNode<T>(number);
                head = tail;
            }
        }

        void pop() {
            if(head != tail) {
                head = head->nextPtr;
                delete head->prevPtr;
            } else {
                delete head;
                head = tail = NULL;
            }
        }

        void pop_back() {
            if(tail != head) {
                tail = tail->prevPtr;
                delete tail->nextPtr;
            } else {
                delete head;
                head = tail = NULL;
            }
        }

        bool empty() {
            if(head == tail && head == NULL) {
                return true;
            } else {
                return false;
            }
        }

        T front() {
            return head->getCoor();
        }

        T back() {
            return tail->getCoor();
        }

    private:
        ListNode<T> *head;
        ListNode<T> *tail;
};

int** minimumStep;
char** grid;
int row, col;
bool visited[1000][1000];
Point pred[1000][1000];
Point position;
Point charge_station;
long int battery, maxBattery, uncleaned_floor = 0;
long long int step = 0;
void BFS(Point s);
Queue<Point> out;

void recharge() {
    battery = maxBattery;
}

int gridMinStep() {
    Queue<Point> que;
    que.push(charge_station);
    minimumStep[charge_station.x][charge_station.y] = 0;
    pred[charge_station.x][charge_station.y] = Point(-1, -1);
    while(!que.empty()) {
        Point p = que.front();
        que.pop();

        if(p.x - 1 >= 0 && visited[p.x - 1][p.y] == false && minimumStep[p.x - 1][p.y] < 0) {
            que.push(Point(p.x - 1, p.y));
            minimumStep[p.x - 1][p.y] = minimumStep[p.x][p.y] + 1;
            pred[p.x - 1][p.y] = Point(p.x, p.y);
        }

        if(p.x + 1 < row && visited[p.x + 1][p.y] == false && minimumStep[p.x + 1][p.y] < 0) {
            que.push(Point(p.x + 1, p.y));
            minimumStep[p.x + 1][p.y] = minimumStep[p.x][p.y] + 1;
            pred[p.x + 1][p.y] = Point(p.x, p.y);
        }

        if(p.y - 1 >= 0 && visited[p.x][p.y - 1] == false && minimumStep[p.x][p.y - 1] < 0) {
            que.push(Point(p.x, p.y - 1));
            minimumStep[p.x][p.y - 1] = minimumStep[p.x][p.y] + 1;
            pred[p.x][p.y - 1] = Point(p.x, p.y);
        }
        if(p.y + 1 < col && visited[p.x][p.y + 1] == false && minimumStep[p.x][p.y + 1] < 0) {
            que.push(Point(p.x, p.y + 1));
            minimumStep[p.x][p.y + 1] = minimumStep[p.x][p.y] + 1;
            pred[p.x][p.y + 1] = Point(p.x, p.y);
        }
    }
}


void printQue(Queue<Point> q) {
    int charge_flag = 0;
    q.pop_back();
    while(!q.empty()) {
        if(q.back().x == charge_station.x && q.back().y == charge_station.y) charge_flag = 1;
        out.push(q.back());
        step++;
        visited[q.back().x][q.back().y] = true;
        grid[q.back().x][q.back().y] = '2';
        battery--;
        q.pop_back();
    }
    if(charge_flag) {
        recharge();
    }
}

void gotoPath(Point s, Point d) {
    int a, b;
    Queue<Point> que;
    if(d.x == charge_station.x && d.y == charge_station.y) {
        while(s.x != d.x || s.y != d.y) {
            que.push_back(s);
            a = pred[s.x][s.y].x;
            b = pred[s.x][s.y].y;
            s.x = a;
            s.y = b;
        }
        que.push_back(s);
    } else if(s.x == charge_station.x && s.y == charge_station.y){
        while(d.x != s.x || d.y != s.y) {
            que.push(d);
            a = pred[d.x][d.y].x;
            b = pred[d.x][d.y].y;
            d.x = a;
            d.y = b;
        }
        que.push(d);
    } else {
        while(d.x != s.x && d.y != s.y) {
            que.push(d);
            a = pred[d.x][d.y].x;
            b = pred[d.x][d.y].y;
            d.x = a;
            d.y = b;
        }
        que.push(d);
    }
    printQue(que);
}

void randomWalkPrint(Point p) {
    out.push(p);
    step++;
    visited[p.x][p.y] = true;
    grid[p.x][p.y] = '2';
    battery--;
    if(p.x == charge_station.x && p.y == charge_station.y) {
        recharge();
    }
}

int findPath() {
    Point s, d;
    s.x = charge_station.x, s.y = charge_station.y;
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            if(minimumStep[i][j] > 0 && visited[i][j] == false && grid[i][j] == '0') {
                d.x = i;
                d.y = j;
                gotoPath(s, d);
                BFS(d);
            } else if(grid[i][j] != 'R') {
                ;
            }
        }
    }
}

void BFS(Point s) {
    Queue<Point> que;
    que.push(s);
    while(!que.empty()) {
        Point p = que.front();
        que.pop();
        if(p.x - 1 >= 0 && visited[p.x - 1][p.y] == false && minimumStep[p.x - 1][p.y] + 1 < battery && grid[p.x - 1][p.y] == '0') {
            que.push(Point(p.x - 1, p.y));
            visited[p.x - 1][p.y] = true;
            randomWalkPrint(Point(p.x - 1, p.y));
        }
        else if(p.x + 1 < row && visited[p.x + 1][p.y] == false && minimumStep[p.x + 1][p.y] + 1 < battery && grid[p.x + 1][p.y] == '0') {
            que.push(Point(p.x + 1, p.y));
            visited[p.x + 1][p.y] = true;
            randomWalkPrint(Point(p.x + 1, p.y));
        }
        else if(p.y - 1 >= 0 && visited[p.x][p.y - 1] == false && minimumStep[p.x][p.y - 1] + 1 < battery && grid[p.x][p.y - 1] == '0') {
            que.push(Point(p.x, p.y - 1));
            visited[p.x][p.y - 1] = true;
            randomWalkPrint(Point(p.x, p.y - 1));
        }
        else if(p.y + 1 < col && visited[p.x][p.y + 1] == false && minimumStep[p.x][p.y + 1] + 1 < battery && grid[p.x][p.y + 1] == '0') {
            que.push(Point(p.x, p.y + 1));
            visited[p.x][p.y + 1] = true;
            randomWalkPrint(Point(p.x, p.y + 1));
        }
        else {
            gotoPath(p, charge_station);
        }

    }
}

int main()
{
	ifstream inFile;

    inFile.open("floor.data");
    if (!inFile) {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }
    freopen("final.path", "w", stdout);
    inFile >> row >> col >> battery;
    maxBattery = battery;
    grid = new char*[row];
    minimumStep = new int*[row];
    for(int i = 0; i < row; i++) {
        grid[i] = new char[col];
        minimumStep[i] = new int[col];
        for(int j = 0; j < col; j++) {
            inFile >> grid[i][j];
            if(grid[i][j] == 'R') {
                charge_station.x = i;
                charge_station.y = j;
                visited[i][j] = true;
            }
            else if(grid[i][j] == '0') {
                uncleaned_floor++;
            } else {
                visited[i][j] = true;
            }
            minimumStep[i][j] = -1;
        }
    }
	inFile.close();
    gridMinStep();
    findPath();
    cout << step << endl;
    cout << charge_station.x << " " << charge_station.y << endl;
    while(!out.empty()) {
        cout << out.front().x << " " << out.front().y << endl;
        out.pop();
    }

}
