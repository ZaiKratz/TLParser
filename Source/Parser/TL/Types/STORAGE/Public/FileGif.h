#pragma once
#include "Engine.h"

#include "../../../Types/Private/FileType.h"

//begin namespace block
namespace STORAGE
{
class FileGif : public PRIVATE::FileType
{
public:
	FileGif();
	~FileGif();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

private:
};
} //end namespace block
