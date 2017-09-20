#include "../Public/UpdateLangPack.h"


//begin namespace block
namespace COMMON
{

UpdateLangPack::UpdateLangPack()
{
	this->_ConstructorID = 1294926422;
}

UpdateLangPack::UpdateLangPack(COMMON::LangPackDifference* difference)
{
	this->_ConstructorID = 1294926422;
	this->difference = difference;
}
void UpdateLangPack::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->difference->OnSend(Writer);
}


void UpdateLangPack::OnResponce(BinaryReader& Reader)
{
	difference = reinterpret_cast<COMMON::LangPackDifference*>(Reader.TGReadObject());
}
UpdateLangPack::~UpdateLangPack()
{

}
}//end namespace block
