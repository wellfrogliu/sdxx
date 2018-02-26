// caffe.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	//leveldb::DB* db;
	//leveldb::Options options;
	//options.create_if_missing = true;
	//leveldb::Status status = leveldb::DB::Open(options, "/tmp/testdb", &db);
	//assert(status.ok());
	//std::string key = "key";
	//std::string value = "value";


	//
	//Caffe_Predefine();
	//Mat lena = imread("D:\\src\\caffe\\vs\\caffe\\x64\\Release\\01-6m.jpg");
	//if (!lena.empty())
	//{
	//	int i = 0;
	//	vector<float> print = ExtractFeature(lena);
	//	while (i<print.size())
	//	{
	//		cout << print[i++] << endl;
	//	}
	//	print.
	//	status = db->Put(leveldb::WriteOptions(), key, value);
	//	assert(status.ok());

	//	status = db->Get(leveldb::ReadOptions(), key, &value);
	//	assert(status.ok());
	//	std::cout << value << std::endl;
	//	std::string key2 = "key2";
	//}
	vector<float> a = { 1.0, 2.5 };
	std::ofstream   outfile("data.txt");
	//uint32_t leng_a = sizeof(float)* 
	std::copy(a.begin(), a.end(), std::ostream_iterator<float>(outfile, " "));
	outfile.close();//
	//imshow("Extract feature", lena);
	//waitKey(0);
	//delete db;
	return 0;
}
