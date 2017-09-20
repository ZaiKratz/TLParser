#include "../Public/ExportedMessageLink.h"


//begin namespace block
namespace COMMON
{

ExportedMessageLink::ExportedMessageLink()
{
	this->_ConstructorID = 57165855;
}

ExportedMessageLink::ExportedMessageLink(FString link)
{
	this->_ConstructorID = 57165855;
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
}
ExportedMessageLink::~ExportedMessageLink()
{

}
}//end namespace block
