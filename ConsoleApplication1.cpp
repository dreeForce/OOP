#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class MemoryBlock {
    private:
        string appName;
        int start;
        int end;
        bool read;
    public:
        MemoryBlock(string appName, int start, int end, bool read) {
            this->appName = appName;
            this->start = start;
            this->end = end;
            this->read = read;
        }
        string getAppName() const {
            return appName;
        }
        int getStart() const {
            return start;
        }
        int getEnd() const {
            return end;
        }
        bool isRead() const {
            return read;
        }
        void setRead(bool read) {
            this->read = read;
        }
        bool operator < (const MemoryBlock& other) const {
            return start < other.start;
        }
        bool operator == (const MemoryBlock& other) const {
            return start == other.start;
        }
};

int main() {

    vector <MemoryBlock> memoryBlocks;

    memoryBlocks.push_back(MemoryBlock("App1", 0, 100, false));
    memoryBlocks.push_back(MemoryBlock("App2", 100, 200, false));
    memoryBlocks.push_back(MemoryBlock("App3", 200, 300, false));
    
    sort(memoryBlocks.begin(), memoryBlocks.end());

    for (const auto& block : memoryBlocks) {
        cout << "App name: " << block.getAppName() << ", start address: " << block.getStart();
        cout << ", end address: " << block.getEnd() << ", read: " << block.isRead() << endl;
    }
    for (auto& block : memoryBlocks) {
        if (block.getAppName() == "App2") {
            block.setRead(true);
            break;
        }
    }

    cout << "---------------------------------------" << endl;

    for (const auto& block : memoryBlocks) {
        cout << "App name: " << block.getAppName() << ", start address: " << block.getStart();
        cout << ", end address: " << block.getEnd() << ", read: " << block.isRead() << endl;
    }
}

