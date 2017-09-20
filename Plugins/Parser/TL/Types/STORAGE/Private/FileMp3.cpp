#include "../Public/FileMp3.h"


//begin namespace block
namespace STORAGE
{

FileMp3::FileMp3()
{
	this->_ConstructorID = 1996917330;
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
}
FileMp3::~FileMp3()
{

}
}//end namespace block
