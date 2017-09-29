#include "../Public/FileJpeg.h"


//begin namespace block
namespace STORAGE
{

FileJpeg::FileJpeg()
{
	this->_ConstructorID = 8322574;
}
void FileJpeg::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void FileJpeg::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
	this->_Responded = true;
}
FileJpeg::~FileJpeg()
{

}
}//end namespace block
