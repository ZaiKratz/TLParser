#include "../Public/InputMessagesFilterPhotoVideoDocuments.h"


//begin namespace block
namespace COMMON
{

InputMessagesFilterPhotoVideoDocuments::InputMessagesFilterPhotoVideoDocuments()
{
	this->_ConstructorID = -648121413;
}
void InputMessagesFilterPhotoVideoDocuments::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void InputMessagesFilterPhotoVideoDocuments::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
	this->_Responded = true;
}
InputMessagesFilterPhotoVideoDocuments::~InputMessagesFilterPhotoVideoDocuments()
{
}
}//end namespace block
