#include "../Public/FileWebp.h"


//begin namespace block
namespace STORAGE
{

FileWebp::FileWebp()
{
	this->_ConstructorID = 276907596;
}
void FileWebp::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void FileWebp::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
	this->_Responded = true;
}
FileWebp::~FileWebp()
{
}
}//end namespace block
