/***********************************************************
  > File Name: 1337.hpp
  > Author: TALBW
  > Created Time: Sat 26 Feb 2022 06:13:33 PM CST
 *******************************************************/

#ifndef BPT_MEMORYRIVER_HPP
#define BPT_MEMORYRIVER_HPP

#include <fstream>
#include <string>
#include <queue>

using std::string;
using std::fstream;
using std::ifstream;
using std::ofstream;

template<class T, int info_len = 2>
class MemoryRiver {
private:
    fstream file;
    string file_name;
    int sizeofT = sizeof(T);
	int St = info_len << 2;
	std::queue<int> Recycle;
	int Index = 0;
public:
    MemoryRiver() = default;

    MemoryRiver(const string& file_name) : file_name(file_name) {}

    void initialise(string FN = "") {
        if (FN != "") file_name = FN;
        file.open(file_name, std::ios::out);
        int tmp = 0;
        for (int i = 0; i < info_len; ++i)
            file.write(reinterpret_cast<char *>(&tmp), sizeof(int));
        file.close();
    }

    //读出第n个int的值赋给tmp，1_base
    void get_info(int &tmp, int n) {
        if (n > info_len) return;
		file.open(file_name, std::ios::in | std::ios::out);
		file.seekg((n - 1) << 2);
		file.read(reinterpret_cast<char *>(&tmp), sizeof(int));
		file.close();
    }

    //将tmp写入第n个int的位置，1_base
    void write_info(int tmp, int n) {
        if (n > info_len) return;
		file.open(file_name, std::ios::in | std::ios::out);
		file.seekp((n - 1) << 2);
		file.write(reinterpret_cast<char *>(&tmp), sizeof(int));
		file.close();
    }

    //在文件合适位置写入类对象t，并返回写入的位置索引index
    //位置索引意味着当输入正确的位置索引index，在以下三个函数中都能顺利的找到目标对象进行操作
    //位置索引index可以取为对象写入的起始位置
    int write(T &t) {
		int id;
		if (!Recycle.empty()) {
			id = Recycle.front();
			Recycle.pop();
		} else id = ++Index;

		file.open(file_name, std::ios::in | std::ios::out);
		file.seekp(St + id * sizeofT);
		file.write(reinterpret_cast<char *>(&t), sizeofT);
		file.close();
		return id;
    }

    //用t的值更新位置索引index对应的对象，保证调用的index都是由write函数产生
    void update(T &t, const int index) {
		file.open(file_name, std::ios::in | std::ios::out);
		file.seekp(St + index * sizeofT);
		file.write(reinterpret_cast<char *>(&t), sizeofT);
		file.close();
    }

    //读出位置索引index对应的T对象的值并赋值给t，保证调用的index都是由write函数产生
    void read(T &t, const int index) {
		file.open(file_name, std::ios::in | std::ios::out);
		file.seekg(St + index * sizeofT);
		file.read(reinterpret_cast<char *>(&t), sizeofT);
		file.close();
    }

    //删除位置索引index对应的对象(不涉及空间回收时，可忽略此函数)，保证调用的index都是由write函数产生
    void Delete(int index) {
		Recycle.push(index);
    }
};


#endif //BPT_MEMORYRIVER_HPP
