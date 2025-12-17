#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    // 设置随机种子
    srand(time(0));
    
    cout << "===== 猜数字游戏 =====" << endl;
    cout << "我想了一个1-100之间的数字" << endl;
    cout << "你有10次机会猜中它" << endl;
    cout << "=====================" << endl;
    
    int bestScore = 100;  // 记录最好成绩
    char playAgain;
    
    do {
        // 生成随机数
        int secretNumber = rand() % 100 + 1;
        int guess;
        int attempts = 0;
        
        cout << "\n新游戏开始！" << endl;
        
        // 游戏主循环
        while (attempts < 10) {
            cout << "第" << attempts + 1 << "次猜测：";
            cin >> guess;
            
            // 输入检查
            if (cin.fail() || guess < 1 || guess > 100) {
                cout << "请输入1-100之间的数字！" << endl;
                cin.clear();  // 清除错误状态
                cin.ignore(100, '\n');  // 忽略错误输入
                continue;
            }
            
            attempts++;
            
            if (guess > secretNumber) {
                cout << "太大了！" << endl;
            } else if (guess < secretNumber) {
                cout << "太小了！" << endl;
            } else {
                cout << "恭喜！猜对了！" << endl;
                cout << "你用了 " << attempts << " 次猜中" << endl;
                
                // 更新最好成绩
                if (attempts < bestScore) {
                    bestScore = attempts;
                    cout << "🎉 创造了新纪录！" << endl;
                }
                break;
            }
            
            // 提示剩余次数
            if (attempts < 10) {
                cout << "你还有 " << 10 - attempts << " 次机会" << endl;
            }
        }
        
        // 如果没猜中
        if (attempts == 10) {
            cout << "很遗憾，10次机会用完了！" << endl;
            cout << "正确答案是：" << secretNumber << endl;
        }
        
        // 显示当前最好成绩
        cout << "\n当前最好成绩：" << bestScore << " 次" << endl;
        
        // 询问是否继续
        cout << "\n是否再玩一次？(y/n)：";
        cin >> playAgain;
        
    } while (playAgain == 'y' || playAgain == 'Y');
    
    cout << "\n===== 游戏结束 =====" << endl;
    cout << "最终最好成绩：" << bestScore << " 次" << endl;
    cout << "感谢游玩！" << endl;
    
    return 0;
}