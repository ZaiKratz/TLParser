#include "../Public/ExportedMessageLink.h"


//begin namespace block
namespace COMMON
{

ExportedMessageLink::ExportedMessageLink()
{
	this->_ConstructorID = 524838915;
}

ExportedMessageLink::ExportedMessageLink(FString link)
{
	this->_ConstructorID = 524838915;
	this->link = link;
}
void ExportedMessageLink::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.TGWriteString(this->link);
}


void ExportedMessageLink::OnResponce(BinaryReader& Reader)
{
	link = Reader.TGReadString();
	this->_Responded = true;
}
ExportedMessageLink::~ExportedMessageLink()
{

}
}//end namespace block
