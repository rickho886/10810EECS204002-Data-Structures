#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "../include/rules.h"
#include "../include/algorithm.h"
#include "../include/board.h"

using namespace std;

class Board_public {
public:
    Cell cells[ROW][COL];
    Board_public(){
        ////// Initialize the borad with correct capacity //////
        // The corners of the board
        cells[0][0].set_capacity(2), cells[0][5].set_capacity(2),
        cells[4][0].set_capacity(2), cells[4][5].set_capacity(2);

        // The edges of the board
        cells[0][1].set_capacity(3), cells[0][2].set_capacity(3), cells[0][3].set_capacity(3), cells[0][4].set_capacity(3),
        cells[1][0].set_capacity(3), cells[2][0].set_capacity(3), cells[3][0].set_capacity(3),
        cells[1][5].set_capacity(3), cells[2][5].set_capacity(3), cells[3][5].set_capacity(3),
        cells[4][1].set_capacity(3), cells[4][2].set_capacity(3), cells[4][3].set_capacity(3), cells[4][4].set_capacity(3);

    }

    bool place_orb(int i, int j, Player * player){

        if(index_range_illegal(i, j) || !placement_illegal(*player, cells[i][j])){
            int temp = cells[i][j].get_orbs_num();
            temp += 1;
            cells[i][j].set_orbs_num(temp);
            cells[i][j].set_color(player->get_color());
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
        int orb_num = cells[i][j].get_orbs_num();
        orb_num ++;
        cells[i][j].set_orbs_num(orb_num);
        cells[i][j].set_color(color);
    }

    void cell_reset(int i, int j){
        cells[i][j].set_orbs_num(0);
        cells[i][j].set_explode(false);
        cells[i][j].set_color('w');
    }

    void cell_explode(int i, int j){
        int orb_num;
        char color = cells[i][j].get_color();

        cell_reset(i, j);

        if( i + 1 < ROW){
            add_orb(i+1, j, color);
        }

        if( j + 1 < COL){
            add_orb(i, j+1, color);
        }

        if( i - 1 >= 0){
            add_orb(i-1, j, color);
        }

        if( j - 1 >= 0){
            add_orb(i, j-1, color);
        }
    }

    void cell_reaction_marker(){

        // Mark the next cell whose number of orbs is equal to the capacity
        for(int i = 0; i < ROW; i++){
                for(int j = 0; j < COL; j++){
                    cell_is_full(&cells[i][j]);
                }
            }
    }

    void cell_chain_reaction(Player player){

        bool chain_reac = true;

        while(chain_reac){

            chain_reac = false;

            for(int i = 0; i < ROW; i++){
                for(int j = 0; j < COL; j++){
                    if(cells[i][j].get_explode()){
                        cell_explode(i ,j);
                        chain_reac = true;
                    }
                }
            }

            if(win_the_game(player)){
                return;
            }

            cell_reaction_marker();
        }
    }

    bool win_the_game(Player player){

        char player_color = player.get_color();
        bool win = true;

        for(int i = 0; i < ROW; i++){
            for(int j = 0; j < COL; j++){
                if(cells[i][j].get_color() == player_color || cells[i][j].get_color() == 'w') continue;
                else{
                    win = false;
                    break;
                }
            }
            if(!win) break;
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
    Point(int val1, int val2) {
        x = val1;
        y = val2;
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
int critical_mass(Point pos) {
    if((pos.x == 0 && pos.y == 0) || (pos.x == ROW-1 && pos.y == COL-1) || (pos.x == ROW-1 && pos.y == 0) || (pos.x == 0 && pos.y == COL-1)) {
        return 2;
    }
    else if(pos.x == 0 || pos.x == ROW-1 || pos.y == 0 || pos.y == COL-1) {
        return 3;
    } else {
        return 4;
    }
}

Queue<Point> neighbour(Point pos) {
    Queue<Point> n;
    if(index_range_illegal(pos.x, pos.y+1)) {
        n.push(Point(pos.x, pos.y+1));
    }
    if(index_range_illegal(pos.x, pos.y-1)) {
        n.push(Point(pos.x, pos.y-1));
    }
    if(index_range_illegal(pos.x+1, pos.y)) {
        n.push(Point(pos.x+1, pos.y));
    }
    if(index_range_illegal(pos.x-1, pos.y)) {
        n.push(Point(pos.x-1, pos.y));
    }
    return n;
}

Board_public move(Board_public board, Point pos, Player currentTurn) {
    Board_public board2 = board;
    board2.place_orb(pos.x, pos.y, &currentTurn);
    return board2;
}

Queue<int> chains(Board_public board, Player player) {
    Board_public board2 = board;
    Queue<int> lengths;
    char playerColor = player.get_color();
    for(int x = 0; x < ROW; x++) {
        for(int y = 0; y < COL; y++) {
            Point pos = Point(x, y);
            if((abs(board2.get_orbs_num(pos.x, pos.y)) == critical_mass(pos) - 1) && (board.get_cell_color(x, y) == playerColor)) {
                int l = 0;
                Queue<Point> visiting_stack;
                visiting_stack.push(pos);
                while(!visiting_stack.empty()) {
                    visiting_stack.pop();
                    pos = visiting_stack.front();
                    board2.cell_reset(pos.x, pos.y);
                    l += 1;
                    Queue<Point> n = neighbour(pos);
                    while(!n.empty()) {
                        Point i = n.front();
                        if((abs(board.get_orbs_num(i.x, i.y)) == critical_mass(i) - 1) && (board.get_cell_color(i.x, i.y) == playerColor)) {
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
    srand(time(NULL));
    int row, col;
    int color = player.get_color();
    while(1){
        row = rand() & 5;
        col = rand() & 6;
        if(board.get_cell_color(row, col) == color || board.get_cell_color(row, col) == 'w') break;
    }

    index[0] = row;
    index[1] = col;
}

int score(Board_public board, Player player) {
    int sc = 0;
    int my_orbs = 0;
    int enemy_orbs = 0;
    char playerColor = player.get_color();
    for(int x = 0; x < ROW; x++) {
        for(int y = 0; y < COL; y++) {
            Point pos = Point(x, y);
            if(board.get_cell_color(pos.x, pos.y) == playerColor) {
                my_orbs += abs(board.get_orbs_num(pos.x, pos.y));
                bool flag_not_vulnerable = true;
                Queue<Point> n = neighbour(pos);
                while(!n.empty()) {
                    Point i = n.front();
                    if(board.get_cell_color(i.x, i.y) != playerColor && abs(board.get_orbs_num(i.x, i.y)) == critical_mass(i) - 1) {
                        sc -= 5 - critical_mass(i);
                        flag_not_vulnerable = false;
                    }
                }
                if(flag_not_vulnerable) {
                    if(critical_mass(pos) == 3) {
                        sc += 2;
                    }
                    else if(critical_mass(pos) == 2) {
                        sc += 3;
                    }
                    if(abs(board.get_orbs_num(pos.x, pos.y)) == critical_mass(pos) - 1) {
                        sc += 2;
                    }
                }
            }
            else {
                enemy_orbs += abs(board.get_orbs_num(x, y));
            }
        }
    }

    sc += my_orbs;
    if(enemy_orbs == 0 && my_orbs > 1) {
        return 10000;
    }

    else if(my_orbs == 0 && enemy_orbs > 1) {
        return -10000;
    }

    Queue<int> c = chains(board, player);
    while(!c.empty()) {
        int i = c.front();
        if(i > 1) {
            sc += 2*i;
        }
        c.pop();
    }

    return sc;
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
            Point pos = Point(i, j);
            if(board.get_cell_color(pos.x, pos.y) == colorPlayer || board.get_cell_color(pos.x, pos.y) == 'w') {
                conf[i*10+j] = score(move(board, pos, player), player);
            }
        }
    }
    return conf;
}

Pair<Point, int> minimax(Board_public board, int depth, int breadth, Player player) {
    int i, j, k;
    int *best_moves = bestn(board, player);
    Point best_pos[breadth];
    int best_val[breadth];
    Point best_next_pos;
    int best_next_val;
    char playerColor = player.get_color();
    char enemyColor;
    if(playerColor == 'r') {
        enemyColor = 'b';
    } else {
        enemyColor = 'b';
    }

    i = 0;
    while(i < breadth) {
        best_pos[i].x = 0;
        best_pos[i].y = 0;
        best_val[i] = -10000;
        i++;
    }

    i = 0, j = 0, k = breadth-1;
    while(i < 100) {
        if(i%10 > 5 || i/10 > 4 || board.get_cell_color(i/10, i%10)== enemyColor) continue;
        while(j < breadth) {
            if(best_moves[i] > best_val[j]) {
                while(k >= j+1) {
                    best_val[k] = best_val[k-1];
                    best_pos[k].x = best_pos[k-1].x;
                    best_pos[k].y = best_pos[k-1].y;
                    k--;
                }
                best_val[j] = best_moves[i];
                best_pos[j].x = i/10;
                best_pos[j].y = i%10;
                break;
            }
            j++;
        }
        i++;
    }
    delete []best_moves;
    best_next_pos = best_pos[0];
    best_next_val = score(move(board, best_next_pos, player), player);

    if(depth==1) {
        Pair<Point, int> ret(best_next_pos, best_next_val);
        return ret;
    }
    i = 0;
    while(i < breadth) {
        Board_public b_new = move(board, best_pos[i], player);
        Pair<Point, int> best_move = minimax(b_new, depth-1, breadth, player);
        int val = best_move.second;
        if(best_next_val < val) {
            best_next_val = val;
            best_next_pos = best_pos[i];
        }
        i++;
    }

    Pair<Point, int> ret(best_next_pos, best_next_val);
    return ret;
}
