#include "../Public/UpdateStickerSets.h"


//begin namespace block
namespace COMMON
{

UpdateStickerSets::UpdateStickerSets()
{
	this->_ConstructorID = 1135492588;
}
void UpdateStickerSets::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void UpdateStickerSets::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
	this->_Responded = true;
}
UpdateStickerSets::~UpdateStickerSets()
{

}
}//end namespace block
