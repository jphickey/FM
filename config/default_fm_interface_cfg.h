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
 */
#ifndef FM_INTERFACE_CFG_H
#define FM_INTERFACE_CFG_H

/**
 * \defgroup cfsfmmissioncfg CFS File Manager Mission Configuration
 * \{
 */

/**
 * \brief Number of Free Space Table Entries
 *
 *  \par Description:
 *       This value defines the number of entries in both the FM file system
 *       free space table and the FM file system free space telemetry packet.
 *       Note: this value does not define the number of file systems present
 *       or supported by the CFE-OSAL, the value only defines the number of
 *       file systems for which FM may be enabled to report free space data.
 *
 *  \par Limits:
 *       FM limits this value to be not less than 1 and not greater than 32.
 */
#define FM_TABLE_ENTRY_COUNT 8

/**
 * \brief Directory List Telemetry Packet Entry Count
 *
 *  \par Description:
 *       This definition sets the number of directory entries contained
 *       in the Directory List telemetry packet.  The command handler will
 *       read directory entries until reaching the index of the start entry
 *       (set via command argument) and then continue to read
 *       directory entries and populate the telemtry packet until there are
 *       either no more unread directory entries or until the telemetry
 *       packet is full.
 *
 *  \par Limits:
 *       The FM application limits this value to be no less than 10 and
 *       and no greater than 100. The number of directory entries in the
 *       telemetry packet will in large part determine the packet size.
 */
#define FM_DIR_LIST_PKT_ENTRIES 20

/**
 * \brief Maximum number of open files handled by FM
 *
 *  \par Description:
 *       This definition sets the number of entries that can be put into
 *       the "Open Files" telemetry packet from FM.  It is recommended to
 *       set this the same as OS_MAX_NUM_OPEN_FILES, but they may be differ.
 *
 *  \par Limits:
 *       Must be greater than 0.
 *       The upper limit depends on the maximum message size for SB;
 *       The larger this value, the larger the telemetry message becomes.
 */
#define FM_MAX_NUM_OPEN_FILES 50

/**\}*/

#endif
