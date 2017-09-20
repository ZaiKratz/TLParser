#include "../Public/SearchGifs.h"


//begin namespace block
namespace MESSAGES
{

SearchGifs::SearchGifs()
{
	this->_ConstructorID = 1803000511;
	this->_ContentRelated = true;
}

SearchGifs::SearchGifs(FString q, int32 offset)
{
	this->_ConstructorID = 1803000511;
	this->_ContentRelated = true;
	this->q = q;
	this->offset = offset;
}
void SearchGifs::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.TGWriteString(this->q);
	Writer.WriteInt(this->offset);
}


void SearchGifs::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<MESSAGES::FoundGifs*>(Reader.TGReadObject());
}
SearchGifs::~SearchGifs()
{

}
}//end namespace block
