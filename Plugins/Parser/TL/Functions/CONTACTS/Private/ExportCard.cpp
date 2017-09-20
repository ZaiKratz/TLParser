#include "../Public/ExportCard.h"


//begin namespace block
namespace CONTACTS
{

ExportCard::ExportCard()
{
	this->_ConstructorID = 926410116;
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
}
ExportCard::~ExportCard()
{

}
}//end namespace block
