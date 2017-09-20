#include "../Public/FileUnknown.h"


//begin namespace block
namespace STORAGE
{

FileUnknown::FileUnknown()
{
	this->_ConstructorID = 87791274;
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
}
FileUnknown::~FileUnknown()
{

}
}//end namespace block
