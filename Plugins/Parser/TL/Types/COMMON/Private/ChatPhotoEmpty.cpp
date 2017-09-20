#include "../Public/ChatPhotoEmpty.h"


//begin namespace block
namespace COMMON
{

ChatPhotoEmpty::ChatPhotoEmpty()
{
	this->_ConstructorID = 469877047;
}
void ChatPhotoEmpty::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void ChatPhotoEmpty::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
}
ChatPhotoEmpty::~ChatPhotoEmpty()
{

}
}//end namespace block
