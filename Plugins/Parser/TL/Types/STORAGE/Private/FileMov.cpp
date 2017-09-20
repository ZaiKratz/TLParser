#include "../Public/FileMov.h"


//begin namespace block
namespace STORAGE
{

FileMov::FileMov()
{
	this->_ConstructorID = -1125447349;
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
}
FileMov::~FileMov()
{

}
}//end namespace block
