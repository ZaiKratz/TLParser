#include "../Public/StickerSetInstallResultArchive.h"


//begin namespace block
namespace MESSAGES
{

StickerSetInstallResultArchive::StickerSetInstallResultArchive()
{
	this->_ConstructorID = 904138920;
}

StickerSetInstallResultArchive::StickerSetInstallResultArchive(TArray<COMMON::StickerSetCovered*>  sets)
{
	this->_ConstructorID = 904138920;
	this->sets = sets;
}
void StickerSetInstallResultArchive::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->sets.Num());
	for(auto X : this->sets)
	{
	X->OnSend(Writer);
	}
}


void StickerSetInstallResultArchive::OnResponce(BinaryReader& Reader)
{
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len12568 = Reader.ReadInt();
	for(int32 i = 0; i < Len12568; i++)
	{
	auto X = reinterpret_cast<COMMON::StickerSetCovered*>(Reader.TGReadObject());
	sets.Add(X);
	}
	this->_Responded = true;
}
StickerSetInstallResultArchive::~StickerSetInstallResultArchive()
{

}
}//end namespace block
