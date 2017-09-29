#include "../Public/ExportCard.h"


//begin namespace block
namespace CONTACTS
{

ExportCard::ExportCard()
{
	this->_ConstructorID = -2065352905;
	this->_ContentRelated = true;
}
void ExportCard::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void ExportCard::OnResponce(BinaryReader& Reader)
{
	Reader.ReadInt();
	int32 Count = Reader.ReadInt();
	for(int32 i = 0; i < Count; i++)
	{
		this->result.Add(Reader.ReadInt());
	}
	this->_Responded = true;
}
ExportCard::~ExportCard()
{

}
}//end namespace block