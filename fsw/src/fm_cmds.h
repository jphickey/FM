/************************************************************************
 * NASA Docket No. GSC-18,918-1, and identified as “Core Flight
 * Software System (cFS) File Manager Application Version 2.6.1”
 *
 * Copyright (c) 2021 United States Government as represented by the
 * Administrator of the National Aeronautics and Space Administration.
 * All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may
 * not use this file except in compliance with the License. You may obtain
 * a copy of the License at http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 ************************************************************************/

/**
 * @file
 *   Specification for the CFS FM ground commands.
 */
#ifndef FM_CMDS_H
#define FM_CMDS_H

#include "cfe.h"
#include "fm_msg.h"

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                                 */
/* FM command handler function prototypes                          */
/*                                                                 */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/**
 *  \brief Move File Command Handler Function
 *
 *  \par Description
 *       This function generates an event that displays the application version
 *       numbers.
 *
 *  \par Assumptions, External Events, and Notes:
 *
 *  \param [in]  MsgPtr Pointer to Software Bus command packet.
 *
 *  \returns CFE status response
 *  \retval #CFE_SUCCESS  Command successful
 *
 *  \sa #FM_NOOP_CC, #FM_NoopCmd_t
 */
CFE_Status_t FM_NoopCmd(const FM_NoopCmd_t *MsgPtr);

/**
 *  \brief Reset Counters Command Handler Function
 *
 *  \par Description
 *       This function resets the FM housekeeping telemetry counters.
 *
 *  \par Assumptions, External Events, and Notes:
 *
 *  \param [in]  MsgPtr Pointer to Software Bus command packet.
 *
 *  \returns CFE status response
 *  \retval #CFE_SUCCESS  Command successful
 *
 *  \sa #FM_RESET_COUNTERS_CC, #FM_ResetCountersCmd_t
 */
CFE_Status_t FM_ResetCountersCmd(const FM_ResetCountersCmd_t *MsgPtr);

/**
 *  \brief Copy File Command Handler Function
 *
 *  \par Description
 *       This function copies the command specified source file to the command
 *       specified target file.
 *
 *       Because of the possibility that this command might take a very long time
 *       to complete, command argument validation will be done immediately but
 *       copying the file will be performed by a lower priority child task.
 *       As such, the return value for this function only refers to the result
 *       of command argument verification and being able to place the command on
 *       the child task interface queue.
 *
 *  \par Assumptions, External Events, and Notes:
 *
 *  \param [in]  MsgPtr Pointer to Software Bus command packet.
 *
 *  \returns CFE status response
 *  \retval #CFE_SUCCESS  Command successful
 *
 *  \sa #FM_COPY_FILE_CC, #FM_CopyFileCmd_t
 */
CFE_Status_t FM_CopyFileCmd(const FM_CopyFileCmd_t *MsgPtr);

/**
 *  \brief Move File Command Handler Function
 *
 *  \par Description
 *       This function moves the command specified source file to the command
 *       specified target filename.
 *
 *  \par Assumptions, External Events, and Notes:
 *
 *  \param [in]  MsgPtr Pointer to Software Bus command packet.
 *
 *  \returns CFE status response
 *  \retval #CFE_SUCCESS  Command successful
 *
 *  \sa #FM_MOVE_FILE_CC, #FM_MoveFileCmd_t
 */
CFE_Status_t FM_MoveFileCmd(const FM_MoveFileCmd_t *MsgPtr);

/**
 *  \brief Rename File Command Handler Function
 *
 *  \par Description
 *       This function renames the command specified source file to the command
 *       specified target filename.
 *
 *  \par Assumptions, External Events, and Notes:
 *
 *  \param [in]  MsgPtr Pointer to Software Bus command packet.
 *
 *  \returns CFE status response
 *  \retval #CFE_SUCCESS  Command successful
 *
 *  \sa #FM_RENAME_FILE_CC, #FM_RenameFileCmd_t
 */
CFE_Status_t FM_RenameFileCmd(const FM_RenameFileCmd_t *MsgPtr);

/**
 *  \brief Delete File Command Handler Function
 *
 *  \par Description
 *       This function deletes the command specified file.
 *
 *  \par Assumptions, External Events, and Notes:
 *
 *  \param [in]  MsgPtr Pointer to Software Bus command packet.
 *
 *  \returns CFE status response
 *  \retval #CFE_SUCCESS  Command successful
 *
 *  \sa #FM_DELETE_FILE_CC, #FM_DeleteFileCmd_t
 */
CFE_Status_t FM_DeleteFileCmd(const FM_DeleteFileCmd_t *MsgPtr);

/**
 *  \brief Delete All Files Command Handler Function
 *
 *  \par Description
 *       This function deletes all files from the command specified directory.
 *
 *       Because of the possibility that this command might take a very long time
 *       to complete, command argument validation will be done immediately but
 *       reading the directory and deleting each file will be performed by a
 *       lower priority child task.
 *       As such, the return value for this function only refers to the result
 *       of command argument verification and being able to place the command on
 *       the child task interface queue.
 *
 *  \par Assumptions, External Events, and Notes:
 *
 *  \param [in]  MsgPtr Pointer to Software Bus command packet.
 *
 *  \returns CFE status response
 *  \retval #CFE_SUCCESS  Command successful
 *
 *  \sa #FM_DELETE_ALL_FILES_CC, #FM_DeleteAllFilesCmd_t
 */
CFE_Status_t FM_DeleteAllFilesCmd(const FM_DeleteAllFilesCmd_t *MsgPtr);

/**
 *  \brief Decompress Files Command Handler Function
 *
 *  \par Description
 *       This function decompresses the command specified source file into the
 *       command specified target file.
 *
 *       Because of the possibility that this command might take a very long time
 *       to complete, command argument validation will be done immediately but
 *       decompressing the source file into the target file will be performed by
 *       a lower priority child task.
 *       As such, the return value for this function only refers to the result
 *       of command argument verification and being able to place the command on
 *       the child task interface queue.
 *
 *  \par Assumptions, External Events, and Notes:
 *
 *  \param [in]  MsgPtr Pointer to Software Bus command packet.
 *
 *  \returns CFE status response
 *  \retval #CFE_SUCCESS  Command successful
 *
 *  \sa #FM_DECOMPRESS_FILE_CC, #FM_DecompressFileCmd_t
 */
CFE_Status_t FM_DecompressFileCmd(const FM_DecompressFileCmd_t *MsgPtr);

/**
 *  \brief Concatenate Files Command Handler Function
 *
 *  \par Description
 *       This function concatenates two command specified source files into the
 *       command specified target file.
 *
 *       Because of the possibility that this command might take a very long time
 *       to complete, command argument validation will be done immediately but
 *       copying the first source file to the target file and then appending the
 *       second source file to the target file will be performed by a lower priority
 *       child task.
 *       As such, the return value for this function only refers to the result
 *       of command argument verification and being able to place the command on
 *       the child task interface queue.
 *
 *  \par Assumptions, External Events, and Notes:
 *
 *  \param [in]  MsgPtr Pointer to Software Bus command packet.
 *
 *  \returns CFE status response
 *  \retval #CFE_SUCCESS  Command successful
 *
 *  \sa #FM_CONCAT_FILES_CC, #FM_ConcatFilesCmd_t
 */
CFE_Status_t FM_ConcatFilesCmd(const FM_ConcatFilesCmd_t *MsgPtr);

/**
 *  \brief Get File Information Command Handler Function
 *
 *  \par Description
 *       This function creates a telemetry packet and populates the packet with
 *       the current information regarding the command specified file.
 *
 *       Because of the possibility that this command might take a very long time
 *       to complete, command argument validation will be done immediately but
 *       collecting the status data and calculating the CRC will be performed by
 *       a lower priority child task.
 *       As such, the return value for this function only refers to the result
 *       of command argument verification and being able to place the command on
 *       the child task interface queue.
 *
 *  \par Assumptions, External Events, and Notes:
 *
 *  \param [in]  MsgPtr Pointer to Software Bus command packet.
 *
 *  \returns CFE status response
 *  \retval #CFE_SUCCESS  Command successful
 *
 *  \sa #FM_GET_FILE_INFO_CC, #FM_GetFileInfoCmd_t, #FM_FileInfoPkt_t
 */
CFE_Status_t FM_GetFileInfoCmd(const FM_GetFileInfoCmd_t *MsgPtr);

/**
 *  \brief Get Open Files List Command Handler Function
 *
 *  \par Description
 *       This function creates a telemetry packet and populates it with a list of
 *       the current open files.
 *
 *  \par Assumptions, External Events, and Notes:
 *
 *  \param [in]  MsgPtr Pointer to Software Bus command packet.
 *
 *  \returns CFE status response
 *  \retval #CFE_SUCCESS  Command successful
 *
 *  \sa #FM_GET_OPEN_FILES_CC, #FM_GetOpenFilesCmd_t, #FM_OpenFilesPkt_t
 */
CFE_Status_t FM_GetOpenFilesCmd(const FM_GetOpenFilesCmd_t *MsgPtr);

/**
 *  \brief Create Directory Command Handler Function
 *
 *  \par Description
 *       This function creates the command specified directory.
 *
 *  \par Assumptions, External Events, and Notes:
 *
 *  \param [in]  MsgPtr Pointer to Software Bus command packet.
 *
 *  \returns CFE status response
 *  \retval #CFE_SUCCESS  Command successful
 *
 *  \sa #FM_CREATE_DIRECTORY_CC, #FM_CreateDirectoryCmd_t
 */
CFE_Status_t FM_CreateDirectoryCmd(const FM_CreateDirectoryCmd_t *MsgPtr);

/**
 *  \brief Delete Directory Command Handler Function
 *
 *  \par Description
 *       This function deletes the command specified directory.
 *
 *  \par Assumptions, External Events, and Notes:
 *
 *  \param [in]  MsgPtr Pointer to Software Bus command packet.
 *
 *  \returns CFE status response
 *  \retval #CFE_SUCCESS  Command successful
 *
 *  \sa #FM_DELETE_DIRECTORY_CC, #FM_DeleteDirectoryCmd_t
 */
CFE_Status_t FM_DeleteDirectoryCmd(const FM_DeleteDirectoryCmd_t *MsgPtr);

/**
 *  \brief Get Directory List to Packet Command Handler Function
 *
 *  \par Description
 *       This function creates an output file and writes a listing of the command
 *       specified directory to the file.
 *
 *       Because of the possibility that this command might take a very long time
 *       to complete, command argument validation will be done immediately but
 *       reading the directory will be performed by a lower priority child task.
 *       As such, the return value for this function only refers to the result
 *       of command argument verification and being able to place the command on
 *       the child task interface queue.
 *
 *  \par Assumptions, External Events, and Notes:
 *
 *  \param [in]  MsgPtr Pointer to Software Bus command packet.
 *
 *  \returns CFE status response
 *  \retval #CFE_SUCCESS  Command successful
 *
 *  \sa #FM_GET_DIR_LIST_FILE_CC, #FM_GetDirListFileCmd_t,
 *      #FM_DirListFileStats_t, FM_DirListEntry_t
 */
CFE_Status_t FM_GetDirListFileCmd(const FM_GetDirListFileCmd_t *MsgPtr);

/**
 *  \brief Get Directory List to Packet Command Handler Function
 *
 *  \par Description
 *       This function creates a telemetry packet and populates the packet with
 *       the directory listing data for the command specified directory, starting
 *       at the command specified directory entry.
 *
 *       Because of the possibility that this command might take a very long time
 *       to complete, command argument validation will be done immediately but
 *       reading the directory will be performed by a lower priority child task.
 *       As such, the return value for this function only refers to the result
 *       of command argument verification and being able to place the command on
 *       the child task interface queue.
 *
 *  \par Assumptions, External Events, and Notes:
 *
 *  \param [in]  MsgPtr Pointer to Software Bus command packet.
 *
 *  \returns CFE status response
 *  \retval #CFE_SUCCESS  Command successful
 *
 *  \sa #FM_GET_DIR_LIST_PKT_CC, #FM_GetDirListPktCmd_t, #FM_DirListPkt_t
 */
CFE_Status_t FM_GetDirListPktCmd(const FM_GetDirListPktCmd_t *MsgPtr);

/**
 *  \brief Monitor Filesystem Command Handler Function
 *
 *  \par Description
 *       This function creates a telemetry packet and populates the packet with
 *       disk usage data for each location listed in the FM File System Monitor
 *       Table.
 *
 *  \par Assumptions, External Events, and Notes:
 *
 *  \param [in]  MsgPtr Pointer to Software Bus command packet.
 *
 *  \returns CFE status response
 *  \retval #CFE_SUCCESS  Command successful
 *
 *  \sa #FM_MONITOR_FILESYSTEM_SPACE_CC, #FM_MonitorFilesystemSpaceCmd_t, #FM_MonitorReportPkt_t
 */
CFE_Status_t FM_MonitorFilesystemSpaceCmd(const FM_MonitorFilesystemSpaceCmd_t *MsgPtr);

/**
 *  \brief Set Table Entry State Command Handler Function
 *
 *  \par Description
 *       This function modifies the enable/disable state for a single entry in
 *       the File System Free Space Table.
 *
 *  \par Assumptions, External Events, and Notes:
 *
 *  \param [in]  MsgPtr Pointer to Software Bus command packet.
 *
 *  \returns CFE status response
 *  \retval #CFE_SUCCESS  Command successful
 *
 *  \sa #FM_SET_TABLE_STATE_CC, #FM_SetTableStateCmd_t, #FM_MonitorTableEntry_t
 */
CFE_Status_t FM_SetTableStateCmd(const FM_SetTableStateCmd_t *MsgPtr);

/**
 *  \brief Set File Permissions of a file
 *
 *  \par Description
 *       This function is a direct call to OS_chmod to set the file access
 *
 *  \par Assumptions, External Events, and Notes:
 *
 *  \param [in]  MsgPtr Pointer to Software Bus command packet.
 *
 *  \returns CFE status response
 *  \retval #CFE_SUCCESS  Command successful
 *
 *  \sa #FM_SET_PERMISSIONS_CC, #FM_SetPermissionsCmd_t, #FM_SET_PERM_CMD_INF_EID, #FM_SET_PERM_ERR_EID
 */
CFE_Status_t FM_SetPermissionsCmd(const FM_SetPermissionsCmd_t *MsgPtr);

#endif
