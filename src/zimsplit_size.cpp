/*
 * Copyright (C) 2026 Nidhi Gahlawat.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU  General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 */

#include "zimsplit_size.h"

#include <stdexcept>

namespace
{

constexpr auto partSizeTooLargeError
    = "part size must be smaller than the input ZIM file";

}  // namespace

void validatePartSize(uint64_t partSize, uint64_t archiveSize)
{
  if (partSize >= archiveSize) {
    throw std::invalid_argument(partSizeTooLargeError);
  }
}
