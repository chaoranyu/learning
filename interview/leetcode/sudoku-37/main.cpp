#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>

class Solution {
public:
    int readSudoku(std::vector<std::vector<char>>& board) {
        std::fstream fs;
        fs.open("input.csv", std::ios::in);
        if (!fs.is_open()) {
            std::cerr << "opening file failed\n";
            return -1;
        }

        int i = 0;
        for (auto &a : board) {
            for (auto &b : a) {
                fs >> b;
                i += 2;
                fs.seekg(i);
            }
        }
            
        fs.close();
        return 0;
    }

    void solveSudoku(std::vector<std::vector<char>>& board) {
        std::vector<std::pair<int, int>> position;
        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[0].size(); j++)
                if (board[i][j] == '.')
                    position.push_back({i, j});
        solve(board, position, 0);
    }

    void printSudoku(std::vector<std::vector<char>>& board) {
        for (const auto &a : board) {
            for (const auto &b : a) {
                std::cout << b << ' ';
            }
            std::cout << std::endl;
        }
    }

    int writeSudoku(std::vector<std::vector<char>>& board) {
        std::fstream fs;
        fs.open("output.csv", std::ios::out);
        if (!fs.is_open()) {
            std::cerr << "write file failed\n";
            return -1;
        }

        for (const auto &a : board) {
            for (const auto &b : a) {
                fs << b << ',';
            }
            fs << '\n';
        }

        fs.close();
        return 0;
    }

private:
    bool solve(std::vector<std::vector<char>>& board,
               std::vector<std::pair<int, int>>& position, int cur)
    {
        if (cur >= position.size())
            return true;
        else{
            int x=position[cur].first,y=position[cur].second;
            for(int i=0;i<9;i++){//try each
                int ok=1;
                char c=i+'1';
                for(int j=0;j<9;j++)
                    if(board[x][j]==c||board[j][y]==c){ok=0;break;}
                int xs=x/3*3,ys=y/3*3;
                for(int z=xs;z<xs+3;++z)
                    for(int w=ys;w<ys+3;++w)
                        if(board[z][w]==c)
                            ok=0;
                if(ok){
                    board[x][y]=c;
                    if(solve(board,position,cur+1))return true;
                    board[x][y]='.';
                }
            }
        }
        return false;
    }
};

int main() {
    std::vector<std::vector<char>> board(9, std::vector<char>(9, '0'));

    Solution s;
    if (s.readSudoku(board) == -1) return -1;
    s.printSudoku(board);

    auto start =  std::chrono::high_resolution_clock::now();
    s.solveSudoku(board);
    auto end =  std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end -start;
    std::cout << diff.count() << " s\n";

    std::cout << "\n----------------";
    std::cout << "\n|    Answer    |";
    std::cout << "\n----------------\n";
    s.printSudoku(board);

    s.writeSudoku(board);

    return 0;
}
