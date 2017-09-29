#include "../Public/ChatPhotoEmpty.h"


//begin namespace block
namespace COMMON
{

ChatPhotoEmpty::ChatPhotoEmpty()
{
	this->_ConstructorID = 935395612;
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
	this->_Responded = true;
}
ChatPhotoEmpty::~ChatPhotoEmpty()
{

}
}//end namespace block
