#include "../Public/UpdateStickerSets.h"


//begin namespace block
namespace COMMON
{

UpdateStickerSets::UpdateStickerSets()
{
	this->_ConstructorID = -331502013;
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
}
UpdateStickerSets::~UpdateStickerSets()
{

}
}//end namespace block
