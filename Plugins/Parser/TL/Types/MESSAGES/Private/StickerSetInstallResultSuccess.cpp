#include "../Public/StickerSetInstallResultSuccess.h"


//begin namespace block
namespace MESSAGES
{

StickerSetInstallResultSuccess::StickerSetInstallResultSuccess()
{
	this->_ConstructorID = 672556088;
}
void StickerSetInstallResultSuccess::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void StickerSetInstallResultSuccess::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
}
StickerSetInstallResultSuccess::~StickerSetInstallResultSuccess()
{

}
}//end namespace block
