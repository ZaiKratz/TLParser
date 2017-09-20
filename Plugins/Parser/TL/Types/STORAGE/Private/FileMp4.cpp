#include "../Public/FileMp4.h"


//begin namespace block
namespace STORAGE
{

FileMp4::FileMp4()
{
	this->_ConstructorID = -459223373;
}
void FileMp4::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void FileMp4::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
}
FileMp4::~FileMp4()
{

}
}//end namespace block
