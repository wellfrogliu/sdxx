// caffe.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	leveldb::DB* db;
	leveldb::Options options;
	options.create_if_missing = true;
	leveldb::Status status = leveldb::DB::Open(options, "H:\\caffe\\vs\\caffe\\x64\\Release\\testdb", &db);
	assert(status.ok());
	//std::string key = "key";
	//std::string value = "value";


	
	Caffe_Predefine();
	Mat lena = imread("H:\\caffe\\vs\\caffe\\x64\\Release\\01-6m.jpg");
	if (!lena.empty())
	{
		int i = 0;
		vector<float> print = ExtractFeature(lena);
		while (i<print.size())
		{
			cout << print[i++] << endl;
		}
		std::ostringstream stream;
		std::copy(print.begin(), print.end(), std::ostream_iterator<float>(stream, " "));
		std::string s = stream.str();
		s.erase(s.length() - 1);
		status = db->Put(leveldb::WriteOptions(), "1", s);
		assert(status.ok());

		std::ofstream   outfile("H:\\caffe\\vs\\caffe\\x64\\Release\\data.txt");
		std::copy(print.begin(), print.end(), std::ostream_iterator<float>(outfile, " "));
		outfile.close();

		std::string value;
		status = db->Get(leveldb::ReadOptions(), "1", &value);
		assert(status.ok());
		std::istringstream iss(value);
		std::vector<float> v;
		// Iterate over the istream, using >> to grab floats
		// and push_back to store them in the vector
		std::copy(std::istream_iterator<float>(iss),
			std::istream_iterator<float>(),
			std::back_inserter(v));
		std::ofstream   outfile1("H:\\caffe\\vs\\caffe\\x64\\Release\\data1.txt");
		std::copy(v.begin(), v.end(), std::ostream_iterator<float>(outfile1, " "));
		outfile1.close();
		/*std::cout << value << std::endl;*/

	}
	//vector<float> a = { 1.0, 2.5 };

	//std::ostringstream stream;
	//std::copy(a.begin(), a.end(), std::ostream_iterator<float>(stream, ","));
	//std::string s = stream.str();
	//s.erase(s.length() - 1);
	//cout << s << endl;
	imshow("Extract feature", lena);
	waitKey(0);
	delete db;
	return 0;
}
