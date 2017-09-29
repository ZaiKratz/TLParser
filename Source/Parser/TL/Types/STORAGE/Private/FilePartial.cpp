#include "../Public/FilePartial.h"


//begin namespace block
namespace STORAGE
{

FilePartial::FilePartial()
{
	this->_ConstructorID = 1086091090;
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
	this->_Responded = true;
}
FilePartial::~FilePartial()
{

}
}//end namespace block
