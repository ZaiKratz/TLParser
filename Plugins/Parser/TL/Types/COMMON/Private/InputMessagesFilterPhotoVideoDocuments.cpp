#include "../Public/InputMessagesFilterPhotoVideoDocuments.h"


//begin namespace block
namespace COMMON
{

InputMessagesFilterPhotoVideoDocuments::InputMessagesFilterPhotoVideoDocuments()
{
	this->_ConstructorID = -1150066983;
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
}
InputMessagesFilterPhotoVideoDocuments::~InputMessagesFilterPhotoVideoDocuments()
{

}
}//end namespace block
