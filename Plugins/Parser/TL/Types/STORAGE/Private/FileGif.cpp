#include "../Public/FileGif.h"


//begin namespace block
namespace STORAGE
{

FileGif::FileGif()
{
	this->_ConstructorID = -542449206;
}
void FileGif::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void FileGif::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
}
FileGif::~FileGif()
{

}
}//end namespace block
