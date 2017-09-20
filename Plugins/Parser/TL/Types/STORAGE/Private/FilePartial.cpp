#include "../Public/FilePartial.h"


//begin namespace block
namespace STORAGE
{

FilePartial::FilePartial()
{
	this->_ConstructorID = 1383054400;
}
void FilePartial::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void FilePartial::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
}
FilePartial::~FilePartial()
{

}
}//end namespace block
