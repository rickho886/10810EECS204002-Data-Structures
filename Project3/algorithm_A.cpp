#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "../include/rules.h"
#include "../include/algorithm.h"

using namespace std;

class Board_public {
public:
    Cell cells[ROW][COL];
    Board_public(){
        ////// Initialize the borad with correct capacity //////
        // The corners of the board
        cells[4][1].set_capacity(3), cells[4][2].set_capacity(3), cells[4][3].set_capacity(3), cells[4][4].set_capacity(3);
		cells[0][1].set_capacity(3), cells[0][2].set_capacity(3), cells[0][3].set_capacity(3), cells[0][4].set_capacity(3);
		cells[1][5].set_capacity(3), cells[2][5].set_capacity(3), cells[3][5].set_capacity(3);
		cells[1][0].set_capacity(3), cells[2][0].set_capacity(3), cells[3][0].set_capacity(3);
		cells[4][0].set_capacity(2), cells[4][5].set_capacity(2);
        cells[0][0].set_capacity(2), cells[0][5].set_capacity(2);
    }

    Board_public(Board board) {
        int i = 0, j = 0;
        while(i < ROW) {
            while(j < COL) {
                cells[i][j].set_color(board.get_cell_color(i, j));
                cells[i][j].set_capacity(board.get_capacity(i, j));
                cells[i][j].set_orbs_num(board.get_orbs_num(i, j));
                j++;
            }
            i++;
            j = 0;
        }
    }

    bool place_orb(int i, int j, Player * player){
        int temp;
        char colorPlayer = player->get_color();
        if(index_range_illegal(i, j) || !placement_illegal(*player, cells[i][j])){
            temp = cells[i][j].get_orbs_num();
            temp = temp + 1;
            cells[i][j].set_orbs_num(temp);
            cells[i][j].set_color(colorPlayer);
        }
        else{
            player->set_illegal();
            return false;
        }

        if(cell_is_full(&cells[i][j])){
            cell_explode(i, j);
            cell_reaction_marker();
            cell_chain_reaction(*player);
        }

        return true;
    }

    bool cell_is_full(Cell* cell){
        if(cell->get_orbs_num() >= cell->get_capacity()){
            cell->set_explode(true);
            return true;
        }
        else return false;
    }

    void add_orb(int i, int j, char color){
        int orb_num;
        orb_num = cells[i][j].get_orbs_num();
        orb_num = orb_num + 1;
        cells[i][j].set_orbs_num(orb_num);
        cells[i][j].set_color(color);
    }

    void cell_reset(int i, int j){
        int num = 0;
        bool f = false;
        cells[i][j].set_orbs_num(num);
        cells[i][j].set_explode(f);
        cells[i][j].set_color('w');
    }

    void cell_explode(int i, int j){
        int orb_num;
        char color = cells[i][j].get_color();

        cell_reset(i, j);
        int right = i + 1;
        int left = i - 1;
        int up = j - 1;
        int down = j + 1;

        if( right < ROW){
            add_orb(right, j, color);
        }

        if( down < COL){
            add_orb(i, down, color);
        }

        if( left >= 0){
            add_orb(left, j, color);
        }

        if( up >= 0){
            add_orb(i, up, color);
        }
    }

    void cell_reaction_marker(){
        int i = 0, j = 0;
        while(i < ROW) {
            while(j < COL) {
                cell_is_full(&cells[i][j]);
                j++;
            }
            i++;
            j = 0;
        }
    }

    void cell_chain_reaction(Player player){
        int i = 0, j = 0;
        bool chain_reac = true;
        while(chain_reac){
            chain_reac = false;
            while(i < ROW) {
                while(j < COL) {
                    if(cells[i][j].get_explode()){
                        cell_explode(i ,j);
                        chain_reac = true;
                    }
                    j++;
                }
                i++;
                j = 0;
            }
            i = 0;
            if(win_the_game(player)){
                return;
            }
            cell_reaction_marker();
        }
    }

    bool win_the_game(Player player){
        int i = 0, j = 0;
        char player_color = player.get_color();
        bool win = true;

        while(i < ROW) {
            while(j < COL) {
                if(cells[i][j].get_color() == player_color || cells[i][j].get_color() == 'w') {
                    j++;
                    continue;
                }
                else{
                    win = false;
                    break;
                }
                j++;
            }
            if(!win) break;
            i++;
            j = 0;
        }
        return win;
    }

    int get_orbs_num(int i, int j){
        return cells[i][j].get_orbs_num();
    }

    int get_capacity(int i, int j){
        return cells[i][j].get_capacity();
    }

    char get_cell_color(int i, int j){
        return cells[i][j].get_color();
    }
};

class Point
{
public:
    int x, y;
    Point() {}
    Point(int value1, int value2) {
        x = value1;
        y = value2;
    }
};

template <typename T1, typename T2>
class Pair{
    public:
        T1 first;
        T2 second;
        Pair() {
            ;
        }
        Pair(T1 a, T2 b) {
            first = a;
            second = b;
        }
};

template <typename T>
class ListNode
{
    template <typename Q>
    friend class Queue; //make List_queue a friend
    public:
        ListNode( const T &info ) //constructor
        : coor( info ), nextPtr( NULL ), prevPtr( NULL )
        {
        } //end ListNode constructor

        ListNode operator =(const ListNode &rhs) const {
            return 0;
        }
        T getCoor() {
            return coor;
        }

    private:
        T coor; //data
        ListNode *nextPtr; // next node in list
        ListNode *prevPtr;
}; //end class ListNode

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

Pair<Point, int> minmax(Board_public board, int depth, int breadth, Player player);
int *bestn(Board_public board, Player player);
int score(Board_public board, Player player);
Queue<int> chains(Board_public board, Player player);
Board_public move(Board_public board, Point position, Player currentTurn);
Queue<Point> neighbour(Point position);
int critical_mass(Point position);
/******************************************************
 * In your algorithm, you can just use the the funcitons
 * listed by TA to get the board information.(functions
 * 1. ~ 4. are listed in next block)
 *
 * The STL library functions is not allowed to use.
******************************************************/

/*************************************************************************
 * 1. int board.get_orbs_num(int row_index, int col_index)
 * 2. int board.get_capacity(int row_index, int col_index)
 * 3. char board.get_cell_color(int row_index, int col_index)
 * 4. void board.print_current_board(int row_index, int col_index, int round)
 *
 * 1. The function that return the number of orbs in cell(row, col)
 * 2. The function that return the orb capacity of the cell(row, col)
 * 3. The function that return the color fo the cell(row, col)
 * 4. The function that print out the current board statement
*************************************************************************/
int critical_mass(Point position) {
    if((position.x == 0 && position.y == 0) || (position.x == ROW-1 && position.y == COL-1) || (position.x == ROW-1 && position.y == 0) || (position.x == 0 && position.y == COL-1)) {
        return 2;
    }
    else if(position.x == 0 || position.x == ROW-1 || position.y == 0 || position.y == COL-1) {
        return 3;
    } else {
        return 4;
    }
}

Queue<Point> neighbour(Point position) {
    Queue<Point> n;
    if(0 <= position.x && position.x < ROW && 0 <= position.y+1 && position.y+1 < COL) {
        n.push(Point(position.x, position.y+1));
    }
    if(0 <= position.x && position.x < ROW && 0 <= position.y-1 && position.y-1 < COL) {
        n.push(Point(position.x, position.y-1));
    }
    if(0 <= position.x+1 && position.x+1 < ROW && 0 <= position.y && position.y < COL) {
        n.push(Point(position.x+1, position.y));
    }
    if(0 <= position.x-1 && position.x-1 < ROW && 0 <= position.y && position.y < COL) {
        n.push(Point(position.x-1, position.y));
    }
    return n;
}

Board_public move(Board_public board, Point position, Player currentTurn) {
    board.place_orb(position.x, position.y, &currentTurn);
    return board;
}

Queue<int> chains(Board_public board, Player player) {
    Queue<int> lengths;
    char playerColor = player.get_color();

    for(int x = 0; x < ROW; x++) {
        for(int y = 0; y < COL; y++) {
            Point position = Point(x, y);
            if((abs(board.get_orbs_num(position.x, position.y)) == (critical_mass(position) - 1)) && (board.get_cell_color(x, y) == playerColor)) {
                int l = 0;
                Queue<Point> visiting_stack;
                visiting_stack.push(position);
                while(!visiting_stack.empty()) {
                    position = visiting_stack.front();
                    visiting_stack.pop();
                    board.cell_reset(position.x, position.y);
                    l += 1;
                    Queue<Point> n = neighbour(position);
                    while(!n.empty()) {
                        Point i = n.front();
                        n.pop();
                        if((abs(board.get_orbs_num(i.x, i.y)) == (critical_mass(i) - 1)) && (board.get_cell_color(i.x, i.y) == playerColor)) {
                            visiting_stack.push(i);
                        }

                    }
                }
                lengths.push(l);
            }
        }
    }
    return lengths;
}

void algorithm_A(Board board, Player player, int index[]) {

    // cout << board.get_capacity(0, 0) << endl;
    // cout << board.get_orbs_num(0, 0) << endl;
    // cout << board.get_cell_color(0, 0) << endl;
    // board.print_current_board(0, 0, 0);

    //////////// Random Algorithm ////////////
    // Here is the random algorithm for your reference, you can delete or comment it.
    int x, y;
    Pair<Point, int> best_move;
    Board_public board_pub(board);
    best_move = minmax(board_pub, 2, 10, player);
    x = best_move.first.x;
    y = best_move.first.y;
    index[0] = x;
    index[1] = y;
}

int score(Board_public board, Player player) {
    int score = 0;
    int player_orbs = 0;
    int enemy_orbs = 0;
    char playerColor = player.get_color();
    char enemyColor;
    if(playerColor == 'r') {
        enemyColor = 'b';
    } else {
        enemyColor = 'r';
    }
    for(int x = 0; x < ROW; x++) {
        for(int y = 0; y < COL; y++) {
            Point position = Point(x, y);
            if(board.get_cell_color(position.x, position.y) == playerColor) {
                player_orbs += abs(board.get_orbs_num(position.x, position.y));
                //cout << abs(board.get_orbs_num(position.x, position.y)) << endl;
                bool flag_not_vulnerable = true;
                Queue<Point> n = neighbour(position);
                while(!n.empty()) {
                    Point i = n.front();
                    n.pop();
                    if(board.get_cell_color(i.x, i.y) == enemyColor && abs(board.get_orbs_num(i.x, i.y)) == critical_mass(i) - 1) {
                        score -= 5 - critical_mass(position);
                        flag_not_vulnerable = false;
                    }
                }
                if(flag_not_vulnerable) {
                    if(critical_mass(position) == 3) {
                        score += 2;
                    }
                    else if(critical_mass(position) == 2) {
                        score += 3;
                    }
                    if(abs(board.get_orbs_num(position.x, position.y)) == critical_mass(position) - 1) {
                        score += 2;
                    }
                }
            }
            else {
                enemy_orbs += abs(board.get_orbs_num(position.x, position.y));
            }
        }
    }

    score += player_orbs;
    if(enemy_orbs == 0 && player_orbs > 1) {
        return 10000;
    }
    else if(player_orbs == 0 && enemy_orbs > 1) {
        return -10000;
    }

    Queue<int> c = chains(board, player);
    while(!c.empty()) {
        int i = c.front();
        if(i > 1) {
            score += 2*i;
        }
        c.pop();
    }
    return score;
}

int *bestn(Board_public board, Player player) {
    int *conf = new int[100];
    int i = 0;
    while(i < 100) {
        conf[i] = -10000;
        i++;
    }
    char colorPlayer = player.get_color();
    for(int i = 0; i < ROW; i++) {
        for(int j = 0; j < COL; j++) {
            Point position = Point(i, j);
            if(board.get_cell_color(position.x, position.y) == colorPlayer || board.get_cell_color(position.x, position.y) == 'w') {
                conf[i*10+j] = score(move(board, position, player), player);
            }
        }
    }
    return conf;
}

Pair<Point, int> minmax(Board_public board, int depth, int breadth, Player player) {
    int i, j, k;
    int *best_moves = bestn(board, player);
    int best_value[breadth];
    int value;
    int best_next_value;
    char playerColor = player.get_color();
    char enemyColor;
    Point best_position[breadth];
    Point best_next_position;
    Pair<Point, int> best_move;
    Pair<Point, int> ret;

    if(playerColor == 'r') {
        enemyColor = 'b';
    } else {
        enemyColor = 'r';
    }

    i = 0;
    while(i < breadth) {
        best_position[i].x = 0;
        best_position[i].y = 0;
        best_value[i] = -10000;
        i++;
    }

    i = 0, j = 0, k = breadth-1;
    while(i < 100) {
        if((i%10 > 5 && i/10 > 4) || board.get_cell_color(i/10, i%10)== enemyColor) {
            i++;
            continue;
        }
        while(j < breadth) {
            if(best_moves[i] > best_value[j]) {
                while(k >= j+1) {
                    //cout << "wew" << endl;
                    best_value[k] = best_value[k-1];
                    //cout << best_position[k].x << " " << best_position[k].y << endl;
                    best_position[k].x = best_position[k-1].x;
                    //cout << best_position[k].x << endl;
                    best_position[k].y = best_position[k-1].y;
                    //cout << best_position[k].y << endl;
                    k--;
                }
                best_value[j] = best_moves[i];
                best_position[j].x = i/10;
                best_position[j].y = i%10;
                break;
            }
            j++;
            k = breadth-1;
        }
        i++;
        j = 0;
    }

    delete []best_moves;
    best_next_position = best_position[0];
    //cout << best_next_position.x << " " << best_next_position.y << endl;
    best_next_value = score(move(board, best_next_position, player), player);
    //cout << best_next_value << endl;

    if(depth==1) {
        ret.first = best_next_position;
        ret.second = best_next_value;
        return ret;
    }
    i = 0;

    while(i < breadth) {
        Board_public b_new(move(board, best_position[i], player));
        best_move = minmax(b_new, depth-1, breadth, player);
        value = best_move.second;
        if(value > best_next_value) {
            best_next_value = value;
            best_next_position = best_position[i];
        }
        i++;
    }

    ret.first = best_next_position;
    ret.second = best_next_value;
    return ret;
}
