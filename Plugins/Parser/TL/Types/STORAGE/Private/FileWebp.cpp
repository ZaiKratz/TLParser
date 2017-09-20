#include "../Public/FileWebp.h"


//begin namespace block
namespace STORAGE
{

FileWebp::FileWebp()
{
	this->_ConstructorID = 1279688976;
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
}
FileWebp::~FileWebp()
{

}
}//end namespace block
