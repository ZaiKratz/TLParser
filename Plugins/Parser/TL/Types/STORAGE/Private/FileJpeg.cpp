#include "../Public/FileJpeg.h"


//begin namespace block
namespace STORAGE
{

FileJpeg::FileJpeg()
{
	this->_ConstructorID = 982654;
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
}
FileJpeg::~FileJpeg()
{

}
}//end namespace block
