#include "../Public/Search.h"


//begin namespace block
namespace CONTACTS
{

Search::Search()
{
	this->_ConstructorID = -669845487;
	this->_ContentRelated = true;
}

Search::Search(FString q, int32 limit)
{
	this->_ConstructorID = -669845487;
	this->_ContentRelated = true;
	this->q = q;
	this->limit = limit;
}
void Search::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.TGWriteString(this->q);
	Writer.WriteInt(this->limit);
}


void Search::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<CONTACTS::Found*>(Reader.TGReadObject());
}
Search::~Search()
{

}
}//end namespace block