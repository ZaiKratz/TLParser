#include "../Public/FileMp3.h"


//begin namespace block
namespace STORAGE
{

FileMp3::FileMp3()
{
	this->_ConstructorID = 1384777335;
}
void FileMp3::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void FileMp3::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
	this->_Responded = true;
}
FileMp3::~FileMp3()
{
}
}//end namespace block
