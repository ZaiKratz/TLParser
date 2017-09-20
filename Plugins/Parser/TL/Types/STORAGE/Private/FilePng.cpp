#include "../Public/FilePng.h"


//begin namespace block
namespace STORAGE
{

FilePng::FilePng()
{
	this->_ConstructorID = 64;
}
void FilePng::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void FilePng::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
}
FilePng::~FilePng()
{

}
}//end namespace block
