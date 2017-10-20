#include "../Public/FileUnknown.h"


//begin namespace block
namespace STORAGE
{

FileUnknown::FileUnknown()
{
	this->_ConstructorID = -1432995067;
}
void FileUnknown::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void FileUnknown::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
	this->_Responded = true;
}
FileUnknown::~FileUnknown()
{
}
}//end namespace block
