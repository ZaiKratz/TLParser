#include "../Public/FileMov.h"


//begin namespace block
namespace STORAGE
{

FileMov::FileMov()
{
	this->_ConstructorID = 1258941372;
}
void FileMov::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void FileMov::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
	this->_Responded = true;
}
FileMov::~FileMov()
{

}
}//end namespace block
